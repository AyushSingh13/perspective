[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let isLeapYear = year =>
  year mod 4 == 0 && year mod 100 != 0 || year mod 400 == 0 ? true : false;

let dayCount = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365];

let getDayOfYear = (year, month, dayOfMonth) =>
  isLeapYear(year) ?
    List.nth(dayCount, month) + dayOfMonth :
    List.nth(dayCount, month) + dayOfMonth + 1;

let getDaysInMonth = (year, month) =>
  isLeapYear(year) && month + 1 == 2 ?
    List.nth(dayCount, month + 1) - List.nth(dayCount, month) + 1 :
    List.nth(dayCount, month + 1) - List.nth(dayCount, month);

let make = _children => {
  ...component,
  render: _self => {
    let currentTime = Js.Date.make();
    /* Day */
    let hour = Js.Date.getHours(currentTime);
    let minutes = Js.Date.getMinutes(currentTime);
    let elapsedDay = (hour +. minutes /. 60.) /. 24.;
    
    /* Year */
    let currYear = int_of_float(Js.Date.getFullYear(currentTime));
    let currMonth = int_of_float(Js.Date.getMonth(currentTime));
    let dayOfMonth = int_of_float(Js.Date.getDate(currentTime));
    let daysInYear = isLeapYear(currYear) ? 366 : 365;
    let elapsedYear = 
      float_of_int(getDayOfYear(currYear, currMonth, dayOfMonth))
      /. float_of_int(daysInYear);

    /* Month */
    let elapsedMonth =
        float_of_int(dayOfMonth)
        /. float_of_int(getDaysInMonth(currYear, currMonth));

    /* Week */
    let dayOfWeek = Js.Date.getDay(currentTime);
    let elapsedWeek = dayOfWeek /. 7.;
    <div className="App">
      (ReasonReact.string("perspective"))
      <h1> (ReasonReact.string("Day: " ++ string_of_float(elapsedDay *. 100.) ++ "%")) </h1>
      <h1> (ReasonReact.string("Week: " ++ string_of_float(elapsedWeek *. 100.) ++ "%")) </h1>
      <h1> (ReasonReact.string("Month: " ++ string_of_float(elapsedMonth *. 100.) ++ "%")) </h1>
      <h1> (ReasonReact.string("Year: " ++ string_of_float(elapsedYear *. 100.) ++ "%")) </h1>
    </div>;
  },
};