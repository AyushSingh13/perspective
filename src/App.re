type t;

[%bs.raw {|require('./App.css')|}];

[@bs.new] external createDate : unit => t = "Date";

let dateObj = Js.Date.now();
Js.log(Js.Date.getHours(Js.Date.make()));
Js.log(Js.Date.make());

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    let currentTime = Js.Date.make();
    let hour = Js.Date.getHours(currentTime);
    let elapsedDay =
      "This much of the day as passed: " ++ string_of_float(hour) ++ "/24";
    <div className="App">
      (ReasonReact.string("perspective"))
      <h1> (ReasonReact.string(elapsedDay)) </h1>
    </div>;
  },
};