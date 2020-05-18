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

let serverAxios =
  Instance.create(makeConfig(~baseURL="http://127.0.0.1:8080/api/v1", ()));

let post = (route: string, data) => {
  data
  |> axios->Instance.postData(route)
  |> Js.Promise.then_(response => {Js.Promise.resolve(Ok(response##data))})
  |> Js.Promise.catch(error => error->Errors.catchAsync);
};

let get = (route: string, ~serverSide=false, ()) => {
  let axiosInstance = serverSide ? serverAxios : axios;

  axiosInstance->Instance.get(route)
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