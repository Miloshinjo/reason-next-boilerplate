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
  <AppLayout>
    <div className="bg-gray-200 min-h-screen">
      <div className="mx-auto px-16 py-6">
        {{
           props##spells
           ->Belt.Array.map(spell =>
               <SpellCard
                 key={spell._id}
                 id={spell._id}
                 name={spell.name}
                 level={spell.level}
                 school={spell.school}
                 slug={spell.slug}
               />
             );
         }
         ->React.array}
      </div>
    </div>
  </AppLayout>;
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