open Util;

[@react.component]
let make = (~spells, ~level) => {
  let mapThruSpells = spells => {
    spells
    ->Belt.Array.map(spell =>
        <SpellCard
          key={spell._id}
          id={spell._id}
          name={spell.name}
          level={spell.level}
          school={spell.school}
          description={spell.description}
          concentration={spell.concentration}
          ritual={spell.ritual}
          classes={spell.classes}
          castingTime={spell.castingTime}
          duration={spell.duration}
          slug={spell.slug}
        />
      )
    ->React.array;
  };

  switch (Belt.Array.length(spells)) {
  | 0 => React.null
  | _ =>
    <div className="mb-6">
      <h2 className="font-black text-2xl font-heading text-primary mb-4">
        {switch (level) {
         | "0" => "Cantrips"
         | _ => "Level " ++ level
         }}
        ->React.string
      </h2>
      <div> spells->mapThruSpells </div>
    </div>
  };
};