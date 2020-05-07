open Axios;

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