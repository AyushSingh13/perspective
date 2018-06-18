let component = ReasonReact.statelessComponent("ProgressBar");

let make = (~progress, ~label="", _children) => {
  ...component,
  render: _self => {
    let borderRadius = progress == 0 ? "1em" : "0 1em 1em 0";
    <div
      style=(
        ReactDOMRe.Style.make(
          ~background="linear-gradient(to right, #8BC34A, #FFEB3B, #EF5350)",
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
            ~color="white",
            ~fontWeight="500",
            ~zIndex="2",
            (),
          )
        )>
        (ReasonReact.string(label))
      </div>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~background="#dfe6e9",
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