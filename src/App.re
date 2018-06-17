[%bs.raw {|require('./App.css')|}];
open DateUtils;

type action =
  | TickMinute
  | TickSecond;

type state = {
  minute: float,
  second: float,
};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    minute: Js.Date.make() |> Js.Date.getMinutes,
    second: Js.Date.make() |> Js.Date.getSeconds,
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
      <h3>
        (
          ReasonReact.string(
            "Day: " ++ string_of_float(elapsedDay *. 100.) ++ "%",
          )
        )
      </h3>
      <ProgressBar progress=(int_of_float(elapsedDay *. 100.)) />
      <h3>
        (
          ReasonReact.string(
            "Week: " ++ string_of_float(elapsedWeek *. 100.) ++ "%",
          )
        )
      </h3>
      <ProgressBar progress=(int_of_float(elapsedWeek *. 100.)) />
      <h3>
        (
          ReasonReact.string(
            "Month: " ++ string_of_float(elapsedMonth *. 100.) ++ "%",
          )
        )
      </h3>
      <ProgressBar progress=(int_of_float(elapsedMonth *. 100.)) />
      <h3>
        (
          ReasonReact.string(
            "Year: " ++ string_of_float(elapsedYear *. 100.) ++ "%",
          )
        )
      </h3>
      <ProgressBar progress=(int_of_float(elapsedYear *. 100.)) />
    </div>;
  },
};