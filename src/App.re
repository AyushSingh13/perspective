[%bs.raw {|require('./App.css')|}];
[%bs.raw {|require('./UiComponents.css')|}];
open DateUtils;

type action =
  | TickMinute
  | TickSecond
  | ToggleShowPecentages;

type state = {
  minute: float,
  second: float,
  shouldShowPercent: bool,
};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    minute: Js.Date.make() |> Js.Date.getMinutes,
    second: Js.Date.make() |> Js.Date.getSeconds,
    shouldShowPercent: false,
  },
  reducer: (action, state) =>
    switch (action) {
    | TickMinute =>
      ReasonReact.Update({
        ...state,
        minute: Js.Date.getMinutes(Js.Date.make()),
      })
    | TickSecond =>
      ReasonReact.Update({
        ...state,
        second: Js.Date.getSeconds(Js.Date.make()),
      })
    | ToggleShowPecentages =>
      ReasonReact.Update({
        ...state,
        shouldShowPercent: ! state.shouldShowPercent,
      })
    },
  didMount: self => {
    let intervalId =
      Js.Global.setInterval(() => self.send(TickMinute), 60000);
    let intervalId1 =
      Js.Global.setInterval(() => self.send(TickSecond), 1000);
    self.onUnmount(() => {
      Js.Global.clearInterval(intervalId);
      Js.Global.clearInterval(intervalId1);
    });
  },
  render: self => {
    let currentTime = Js.Date.make();
    /* Day */
    let hour = currentTime |> Js.Date.getHours;
    let elapsedDay =
      (hour +. self.state.minute /. 60. +. self.state.second /. 3600.) /. 24.;

    /* Year */
    let currYear = currentTime |> Js.Date.getFullYear |> int_of_float;
    let currMonth = currentTime |> Js.Date.getMonth |> int_of_float;
    let dayOfMonth = currentTime |> Js.Date.getDate |> int_of_float;
    let daysInYear = isLeapYear(currYear) ? 366 : 365;
    let elapsedYear =
      float_of_int(getDayOfYear(currYear, currMonth, dayOfMonth))
      /. float_of_int(daysInYear);

    /* Month */
    let elapsedMonth =
      float_of_int(dayOfMonth)
      /. float_of_int(getDaysInMonth(currYear, currMonth));

    /* Week */
    let dayOfWeek = currentTime |> Js.Date.getDay;
    let elapsedWeek = dayOfWeek /. 7.;

    <div className="App">
      <InformationHeader />
      <TimeVisualisation
        progress=elapsedDay
        timeType="day"
        shouldShowPercent=self.state.shouldShowPercent
      />
      <TimeVisualisation
        progress=elapsedWeek
        timeType="week"
        shouldShowPercent=self.state.shouldShowPercent
      />
      <TimeVisualisation
        progress=elapsedMonth
        timeType="month"
        shouldShowPercent=self.state.shouldShowPercent
      />
      <TimeVisualisation
        progress=elapsedYear
        timeType="year"
        shouldShowPercent=self.state.shouldShowPercent
      />
      <button
        className="btn" onClick=(_event => self.send(ToggleShowPecentages))>
        (ReasonReact.string("Show Percentage"))
      </button>
    </div>;
  },
};