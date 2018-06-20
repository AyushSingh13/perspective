[%bs.raw {|require('./TimeVisualisation.css')|}];

let component = ReasonReact.statelessComponent("TimeVisualisation");

let make = (~progress, ~timeType, ~shouldShowPercent, ~isDarkMode, _children) => {
  ...component,
  render: _self => {
    let progressLabel =
      timeType ++ ": " ++ (progress *. 100. |> string_of_float) ++ "%";
    <div className="time-vis-container">
      (
        shouldShowPercent ?
          <ProgressBar
            progress=(progress *. 100. |> int_of_float)
            label=progressLabel
            isDarkMode
          /> :
          <ProgressBar
            progress=(progress *. 100. |> int_of_float)
            label=timeType
            isDarkMode
          />
      )
    </div>;
  },
};