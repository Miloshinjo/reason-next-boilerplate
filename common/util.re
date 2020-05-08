module Helpers = {
  let flipBoolean = value => !value;
};

module Email = {
  type t = string;

  let validate = email => {
    let emailRegex = [%bs.re {|/.*@.*\..+/|}];
    switch (email) {
    | "" => Error("Please enter an email")
    | _ as value when !emailRegex->Js.Re.test_(value) =>
      Error("Please enter a valid email")
    | _ => Ok(email)
    };
  };
};

module Password = {
  type t = string;

  let validate = password => {
    switch (password) {
    | "" => Error("Please enter a password")
    | _ when Js.String.length(password) < 8 =>
      Error("Minimum number of characters is 8")
    | _ => Ok(password)
    };
  };
};

module Errors = {
  external promiseErrorToJsObj: Js.Promise.error => Js.t('a) = "%identity";

  let catchAsync = error => {
    let error = error->promiseErrorToJsObj;
    let message =
      switch (error##response##data##message) {
      | None => "An error occured"
      | Some(error) => error
      };

    Js.Promise.resolve(message);
  };
};