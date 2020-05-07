let inputStyles = "text-xl font-medium border bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-3 px-2 text-gray-700 leading-tight focus:outline-none focus:bg-white focus:border-primary";

let labelStyles = "block text-gray-700 text-sm font-bold";

[@react.component]
let make =
    (
      ~id: string,
      ~placeholder: string,
      ~type_: string="text",
      ~label: string,
      ~value: string,
      ~disabled: bool,
      ~error,
      ~onBlur: ReactEvent.Focus.t => unit,
      ~onChange: ReactEvent.Form.t => unit,
    ) =>
  <div className="mb-6">
    <label htmlFor=id className=labelStyles> label->React.string </label>
    <input
      autoComplete="off"
      id
      placeholder
      className=inputStyles
      value
      disabled
      type_
      onBlur
      onChange
    />
    {switch (error) {
     | Some(Error(message)) =>
       <div className="text-yellow-600 font-medium mt-1">
         message->React.string
       </div>
     | Some(Ok(_))
     | None => React.null
     }}
  </div>;

let default = make;