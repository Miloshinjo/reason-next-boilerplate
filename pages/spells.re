[@react.component]
type spell = {
  _id: string,
  name: string,
  level: int,
  school: string,
  slug: string,
};

type props = {. "spells": array(Js.t(spell))};

let make = props => {
  <div className="bg-image min-h-screen text-white">
    {{
       props##spells->Belt.Array.map(spell => <SpellCard key={spell._id} />);
     }
     ->React.array}
  </div>;
};

let default = make;

let getStaticProps: Next.GetStaticProps.t(props, {.}) =
  _ctx => {
    Api.get("/spells?fields=name,level,school,slug", ~serverSide=true, ())
    |> Js.Promise.then_(result => {
         switch (result) {
         | Ok(spells) => Js.Promise.resolve({
                            "props": {
                              spells: spells,
                            },
                          })
         | Error(_) => failwith("This should have been handled by nextjs")
         }
       });
  };