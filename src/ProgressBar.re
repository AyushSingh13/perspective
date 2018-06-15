let component = ReasonReact.statelessComponent("ProgressBar");

let make = (~progress, _children) => {
  ...component,
  render: _self =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~backgroundColor="gray",
          ~height="1.5em",
          ~width="80%",
          (),
        )
      )>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~backgroundColor="#444444",
            ~height="100%",
            ~width=string_of_int(progress) ++ "%",
            (),
          )
        )
      />
    </div>,
};