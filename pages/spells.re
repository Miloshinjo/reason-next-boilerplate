[@react.component]
let make = () => {
  React.useEffect0(() => {
    let spells =
      Api.get("/spells?fields=name,level,school,slug")
      |> Js.Promise.then_(response => {
           switch (response) {
           | Ok(_) => Js.Promise.resolve(Js.log("it's good"))
           | Error(err) => Js.Promise.resolve(Js.log(err))
           }
         });

    None;
  });
  <div className="bg-image min-h-screen"> "Spellbook"->React.string </div>;
};

let default = make;

type spell = {
  name: string,
  level: int,
  school: string,
  slug: string,
};

type props = {spells: list(spell)};

let getStaticProps: Next.GetStaticProps.t(props, {.}) =
  _ctx => {
    let spells =
      Api.get("/spells?fields=name,level,school,slug")
      |> Js.Promise.then_(response => {
           switch (response) {
           | Ok(_) => Js.Promise.resolve(Js.log("it's good SERVER"))
           | Error(err) => Js.Promise.resolve(Js.log(err))
           }
         });

    let props = {spells: []};

    Js.Promise.resolve({"props": props});
  };