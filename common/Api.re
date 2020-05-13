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

let login = (email, password) => {
  let data = {"email": email, "password": password};

  axios->Instance.postData("/users/login", data)
  |> Js.Promise.then_(response => {Js.Promise.resolve(Ok(response##data))})
  |> Js.Promise.catch(error => error->Errors.catchAsync);
};

let register = (email, password, passwordConfirm) => {
  let data = {
    "email": email,
    "password": password,
    "passwordConfirm": passwordConfirm,
  };

  Js.Promise.(
    axios->Instance.postData(
      "/users/signup",
      {
        data;
      },
    )
    |> then_(response => resolve(response##data##token))
    |> catch(error => resolve(Js.log(error)))
  );
};