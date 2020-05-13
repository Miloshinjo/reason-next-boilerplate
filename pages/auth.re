type possibleForms =
  | Login
  | Register;

let buttonStylesActive = "bg-white text-gray-900 transition duration-200";
let buttonStyles = "flex justify-center w-1/2 px-12 py-4 font-bold flex-grow outline-none focus:outline-none transition duration-500";

[@react.component]
let make = () => {
  let (selected, setSelected) = React.useState(() => Login);

  <div
    className="bg-image min-h-screen py-8 px-2 xl:py-32 xl:px-48 flex flex-col xl:flex-row justify-between">
    <div
      className="flex flex-col p-16 items-center justify-center flex-1 text-white">
      <h2 className="uppercase text-xl font-medium">
        "Welcome to"->React.string
      </h2>
      <h1
        className="font-heading text-center uppercase text-6xl font-black
      leading-none">
        "DnD Armory"->React.string
      </h1>
      <p
        className="hidden xl:block text-center mt-10 w-2/3 font-medium text-lg">
        "Get your character sheets in order and track your character progress! Party mode coming soon(tm)!"
        ->React.string
      </p>
      <div className="flex mt-16 overflow-hidden rounded-lg border">
        <button
          className={
            buttonStyles
            ++ " "
            ++ {
              selected === Login ? buttonStylesActive : "";
            }
          }
          onClick={_ => setSelected(_ => Login)}>
          "Login"->React.string
        </button>
        <button
          className={
            buttonStyles
            ++ " "
            ++ {
              selected === Register ? buttonStylesActive : "";
            }
          }
          onClick={_ => setSelected(_ => Register)}>
          "Register"->React.string
        </button>
      </div>
    </div>
    <div className="flex items-center justify-center xl:relative xl:w-2/5">
      <LoginForm selected={selected === Login ? true : false} />
      <RegisterForm selected={selected === Register ? true : false} />
    </div>
  </div>;
};

let default = make;