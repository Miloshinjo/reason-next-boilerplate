[@react.component]
// type props = {. "characters": array(array(Util.character))};
let make = props => {
  <AppLayout>
    <div className="bg-gray-200 min-h-screen py-12">
      <div className="mx-auto flex flex-col px-4 md:px-0 md:w-1/2">
        <div> "Characters"->React.string </div>
      </div>
    </div>
  </AppLayout>;
};

let default = make;
