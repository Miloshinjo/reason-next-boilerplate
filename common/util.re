type spell = {
  _id: string,
  name: string,
  level: int,
  school: string,
  slug: string,
  description: string,
  concentration: bool,
  ritual: bool,
  castingTime: string,
  duration: string,
  classes: array(string),
  components: array(string),
};

module Helpers = {
  let arrangeSpellsByLevel = spells => {
    let extractLevel = level =>
      spells->Belt.Array.keep(spell => spell.level === level);

    let cantrips = extractLevel(0);
    let levelOne = extractLevel(1);
    let levelTwo = extractLevel(2);
    let levelThree = extractLevel(3);
    let levelFour = extractLevel(4);
    let levelFive = extractLevel(5);
    let levelSix = extractLevel(6);
    let levelSeven = extractLevel(7);
    let levelEight = extractLevel(8);
    let levelNine = extractLevel(9);

    [|
      cantrips,
      levelOne,
      levelTwo,
      levelThree,
      levelFour,
      levelFive,
      levelSix,
      levelSeven,
      levelEight,
      levelNine,
    |];
  };
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

    switch (error##response) {
    | Some(_) =>
      switch (error##response##data##message) {
      | Some(_) => Js.Promise.resolve(Error(error##response##data##message))
      | None => Js.Promise.resolve(Error("Weird error occured"))
      }
    | None => Js.Promise.resolve(Error("Weird error occured"))
    };
  };
};

module Auth = {
  let login = (router: Next.Router.router) => {
    Dom.Storage.(localStorage |> setItem("isAuthenticated", "true"));
    router.push("/");
  };
};