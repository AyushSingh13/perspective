[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent("App");

let isLeapYear = year =>
  year mod 4 == 0 && year mod 100 != 0 || year mod 400 == 0 ? true : false;

let dayCount = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];
let getDayOfYear = (year, month, dayOfMonth) =>
  isLeapYear(year) ?
    List.nth(dayCount, month) + dayOfMonth :
    List.nth(dayCount, month) + dayOfMonth + 1;

Js.log(isLeapYear(2020));
let make = _children => {
  ...component,
  render: _self => {
    let currentTime = Js.Date.make();
    /* Day */
    let hour = Js.Date.getHours(currentTime);
    let elapsedDay =
      string_of_float(hour /. 24. *. 100.) ++ "% of the day has passed.";

    /* Year */
    let currYear = int_of_float(Js.Date.getFullYear(currentTime));
    let currMonth = int_of_float(Js.Date.getMonth(currentTime));
    let dayOfMonth = int_of_float(Js.Date.getDate(currentTime));
    let daysInYear = isLeapYear(currYear) ? 366 : 365;
    let elapsedYear =
      string_of_float(
        float_of_int(getDayOfYear(currYear, currMonth, dayOfMonth))
        /. float_of_int(daysInYear)
        *. 100.,
      )
      ++ "% of the year has passed.";
    <div className="App">
      (ReasonReact.string("perspective"))
      <h1> (ReasonReact.string(elapsedDay)) </h1>
      <h1> (ReasonReact.string(elapsedYear)) </h1>
    </div>;
  },
};