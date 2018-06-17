[%bs.raw {|require('./TimeVisualisation.css')|}];

let component = ReasonReact.statelessComponent("TimeVisualisation");

let make = (~progress, ~timeType, _children) => {
  ...component,
  render: _self =>
    <div className="time-vis-container">
      <h3>
        (
          ReasonReact.string(
            timeType ++ ": " ++ (progress *. 100. |> string_of_float),
          )
        )
      </h3>
      <ProgressBar progress=(progress *. 100. |> int_of_float) />
    </div>,
};