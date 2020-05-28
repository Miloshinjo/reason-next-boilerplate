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
      ~components,
      ~range,
      ~attackSave,
      ~damageEffect,
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
        className="block h-6 w-6 mr-4"
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
       ? <div className="px-10 py-2 flex flex-col items-start">
           <div className="grid grid-cols-4 w-full mt-2 row-gap-1">
             <div className="flex flex-col">
               <div className="text-xs"> "Casting time"->React.string </div>
               <div className="font-medium -mt-1">
                 castingTime->React.string
               </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "Duration"->React.string </div>
               <div className="font-medium -mt-1">
                 duration->React.string
               </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "Components"->React.string </div>
               <div className="font-medium uppercase -mt-1">
                 {Js.Array.joinWith(", ", components)->React.string}
               </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "Range"->React.string </div>
               <div className="font-medium -mt-1"> range->React.string </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "School"->React.string </div>
               <div className="font-medium capitalize -mt-1">
                 school->React.string
               </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "Damage/Effect"->React.string </div>
               <div className="font-medium capitalize -mt-1">
                 damageEffect->React.string
               </div>
             </div>
             <div className="flex flex-col">
               <div className="text-xs"> "Attack/Save"->React.string </div>
               <div className="font-medium capitalize -mt-1">
                 attackSave->React.string
               </div>
             </div>
           </div>
           <p className="text mt-3"> description->React.string </p>
           <div className="mt-4 flex justify-between w-full items-center">
             <div className="flex">
               {classes
                ->Belt.Array.map(klass => {
                    <div
                      className={
                        "capitalize mr-2 text-sm font-medium text-" ++ klass
                      }
                      key=klass>
                      klass->React.string
                    </div>
                  })
                ->React.array}
             </div>
             <Link href="/spells/[slug]" _as={"/spells/" ++ slug}>
               <a> "Go to spell page"->React.string </a>
             </Link>
           </div>
         </div>
       : React.null}
  </div>;
};