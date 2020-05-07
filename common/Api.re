open Axios;

let axios =
  Instance.create(makeConfig(~baseURL="http://127.0.0.1:8080/api/v1", ()));

let login = (email, password) => {
  let data = {"email": email, "password": password};

  Js.Promise.(
    axios->Instance.postData(
      "/users/login",
      {
        data;
      },
    )
    |> then_(response => resolve(response##data))
    |> catch(error => resolve(Js.log(error)))
  );
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