open Axios;
module Errors = Util.Errors;

let axios =
  Instance.create(
    makeConfig(
      ~baseURL="/api/v1",
      ~proxy={
        "host": 8080,
        "port": 3000,
        "auth": {
          "username": "",
          "password": "",
        },
      },
      (),
    ),
  );
let post = (route: string, data) => {
  data
  |> axios->Instance.postData(route)
  |> Js.Promise.then_(response => {Js.Promise.resolve(Ok(response##data))})
  |> Js.Promise.catch(error => error->Errors.catchAsync);
};

let get = (route: string) => {
  axios->Instance.get(route)
  |> Js.Promise.then_(response => {Js.Promise.resolve(Ok(response##data))})
  |> Js.Promise.catch(error => error->Errors.catchAsync);
};

let login = (email: string, password: string) => {
  {"email": email, "password": password} |> post("/users/login");
};

let register = (email: string, password: string, passwordConfirm: string) => {
  {"email": email, "password": password, "passwordConfirm": passwordConfirm}
  |> post("/users/signup");
};