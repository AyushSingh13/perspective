let component = ReasonReact.statelessComponent("ProgressBar");

let make = (~progress, ~label="", ~isDarkMode, _children) => {
  ...component,
  render: _self => {
    let borderRadius = progress == 0 ? "1em" : "0 1em 1em 0";
    let startColor = isDarkMode ? "#7f8fa6" : "#8BC34A";
    let middleColor = isDarkMode ? "#718093" : "#FFEB3B";
    let endColor = isDarkMode ? "#c23616" : "#EF5350";
    let labelColor = isDarkMode ? "#dcdde1" : "black";
    let progressBarColor = isDarkMode ? "#2f3640" : "#dfe6e9";
    <div
      style=(
        ReactDOMRe.Style.make(
          ~background=
            {j|linear-gradient(to right, $startColor, $middleColor, $endColor)|j},
          ~borderRadius="1em",
          ~padding="0",
          ~height="1.5em",
          ~width="100%",
          ~display="flex",
          ~flexDirection="column",
          ~alignItems="center",
          ~justifyContent="center",
          (),
        )
      )>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~position="absolute",
            ~color=labelColor,
            ~fontWeight="300",
            ~zIndex="2",
            (),
          )
        )>
        (ReasonReact.string(label))
      </div>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~background=progressBarColor,
            ~opacity="1",
            ~borderRadius,
            ~alignSelf="flex-end",
            ~height="100%",
            ~width=string_of_int(100 - progress) ++ "%",
            (),
          )
        )
      />
    </div>;
  },
};