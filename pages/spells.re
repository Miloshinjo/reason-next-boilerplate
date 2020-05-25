open Util;

[@react.component]
type props = {. "spells": array(array(Util.spell))};

let make = props => {
  <AppLayout>
    <div className="bg-gray-200 min-h-screen py-12">
      <div className="mx-auto flex flex-col px-4 md:px-0 md:w-1/2">
        <div> "Filters"->React.string </div>
        {{
           Belt.Array.mapWithIndex(props##spells, (i, spellGroup) => {
             <SpellSection
               spells=spellGroup
               level={string_of_int(i)}
               key={string_of_int(i)}
             />
           });
         }
         ->React.array}
      </div>
    </div>
  </AppLayout>;
};

let default = make;

let getStaticProps: Next.GetStaticProps.t(props, {.}) =
  _ctx => {
    Api.get("/spells", ~serverSide=true, ())
    |> Js.Promise.then_(result => {
         switch (result) {
         | Ok(spells) =>
           Js.Promise.resolve({
             "props": {
               spells: Helpers.arrangeSpellsByLevel(spells),
             },
           })
         | Error(_) => failwith("This should have been handled by nextjs")
         }
       });
  };