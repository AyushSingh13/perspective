let component = ReasonReact.statelessComponent("InformationHeader");
open DateUtils;

let make = _children => {
  ...component,
  render: _self => {
    let currentTime = Js.Date.make();
    let monthLabel =
      currentTime |> Js.Date.getMonth |> int_of_float |> List.nth(months);
    let date = currentTime |> Js.Date.getDate |> int_of_float;
    let year = currentTime |> Js.Date.getFullYear |> int_of_float;
    <h1
      style=(ReactDOMRe.Style.make(~color="#BDBDBD", ~fontWeight="100", ()))>
      (
        ReasonReact.string(
          monthLabel
          ++ " "
          ++ string_of_int(date)
          ++ ", "
          ++ string_of_int(year),
        )
      )
    </h1>;
  },
};