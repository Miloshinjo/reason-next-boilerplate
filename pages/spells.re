[@react.component]
type spell = {
  _id: string,
  name: string,
  level: int,
  school: string,
  slug: string,
};

type props = {. "spells": Js.t(spell)};

let make = props => {
  Js.log(props##spells);
  <div className="bg-image min-h-screen"> "Spellbook"->React.string </div>;
};

let default = make;

let getStaticProps: Next.GetStaticProps.t(props, {.}) =
  _ctx => {
    Api.get("/spells?fields=name,level,school,slug", ~serverSide=true, ())
    |> Js.Promise.then_(result => {
         switch (result) {
         | Ok(spells) => Js.Promise.resolve({
                            "props": {
                              "spells": spells,
                            },
                          })
         }
       });
  };