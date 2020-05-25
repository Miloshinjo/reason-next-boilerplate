module Link = Next.Link;
open Util;

[@react.component]
let make =
    (
      ~name,
      ~id,
      ~level,
      ~school,
      ~description,
      ~concentration,
      ~slug,
      ~ritual,
      ~classes,
      ~castingTime,
      ~duration,
    ) => {
  let (active, setActive) = React.useState(() => false);

  let handleClick = _ => {
    setActive(active => !active);
  };

  <div
    className={
      "border border-gray-400 my-2 flex flex-col py-2 px-2 rounded cursor-pointer md:hover:shadow-lg md:transition duration-200 md:hover:bg-white"
      ++ {
        active ? " bg-white" : "";
      }
    }
    onClick=handleClick>
    <div className="flex items-center">
      <img
        className="block h-5 w-5 mr-4"
        src={j|/icons/schools/$school.svg|j}
        alt="Spell School"
      />
      <h3 className="font-semibold text-xl"> name->React.string </h3>
      <div className="flex ml-6">
        {concentration
           ? <div
               className="text-xs lowercase bg-blue-200 text-black inline-block px-1 rounded font-medium">
               "Concentration"->React.string
             </div>
           : React.null}
        {ritual && concentration ? <div className="w-2" /> : React.null}
        {ritual
           ? <div
               className="text-xs lowercase bg-purple-200 text-black inline-block px-1 rounded font-medium">
               "Ritual"->React.string
             </div>
           : React.null}
      </div>
      <div className="ml-auto text-sm font-medium">
        {switch (level) {
         | 0 => "Cantrip"->React.string
         | _ =>
           {
             "Lv " ++ string_of_int(level);
           }
           ->React.string
         }}
      </div>
    </div>
    {active
       ? <div className="px-4 py-2 flex flex-col items-start">
           <p className="text-sm mt-2"> description->React.string </p>
         </div>
       : React.null}
  </div>;
};