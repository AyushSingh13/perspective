let component = ReasonReact.statelessComponent("ProgressBar");

let make = (~progress, _children) => {
  ...component,
  render: _self =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~background="linear-gradient(to right, green, yellow, red)",
          ~height="1.5em",
          ~width="80%",
          (),
        )
      )>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~background="#dfe6e9",
            ~opacity="1",
            ~float="right",
            ~height="100%",
            ~width=string_of_int(100 - progress) ++ "%",
            (),
          )
        )
      />
    </div>,
};