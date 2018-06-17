[%bs.raw {|require('./TimeVisualisation.css')|}];

let component = ReasonReact.statelessComponent("TimeVisualisation");

let make = (~progress, ~timeType, ~shouldShowPercent, _children) => {
  ...component,
  render: _self =>
    <div className="time-vis-container">
      (
        shouldShowPercent ?
          <h3 className="time-label">
            (
              ReasonReact.string(
                timeType ++ ": " ++ (progress *. 100. |> string_of_float),
              )
            )
          </h3> :
          ReasonReact.null
      )
      <ProgressBar progress=(progress *. 100. |> int_of_float) />
    </div>,
};