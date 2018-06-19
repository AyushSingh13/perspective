[%bs.raw {|require('./InformationHeader.css')|}];
[%bs.raw {|require('./UiComponents.css')|}];
open DateUtils;

let component = ReasonReact.statelessComponent("InformationHeader");

let make = (~handleDetailToggle, _children) => {
  ...component,
  render: _self => {
    let currentTime = Js.Date.make();
    let monthLabel =
      currentTime |> Js.Date.getMonth |> int_of_float |> List.nth(months);
    let weekLabel =
      currentTime |> Js.Date.getDay |> int_of_float |> List.nth(weekdays);
    let date = currentTime |> Js.Date.getDate |> int_of_float;
    let year = currentTime |> Js.Date.getFullYear |> int_of_float;
    <div className="header-container">
      <div className="date-label">
        <h1> (ReasonReact.string(weekLabel)) </h1>
        <h1>
          (
            ReasonReact.string(
              monthLabel
              ++ " "
              ++ string_of_int(date)
              ++ " "
              ++ string_of_int(year),
            )
          )
        </h1>
      </div>
      <button onClick=handleDetailToggle className="btn">
        (ReasonReact.string("Show Details"))
      </button>
    </div>;
  },
};