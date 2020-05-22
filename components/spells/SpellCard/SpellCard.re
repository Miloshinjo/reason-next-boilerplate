module Link = Next.Link;

[@react.component]
let make = (~name, ~id, ~level, ~school, ~slug) => {
  <Link href="/spells">
    <div
      className="inline-flex py-1 px-2 items-center cursor-pointer hover:shadow-lg transition duration-200 hover:bg-white">
      <img
        className="block h-5 w-5 mr-1"
        src={j|/icons/schools/$school.svg|j}
        alt="Spell School"
      />
      <h3 className="font-medium"> name->React.string </h3>
    </div>
  </Link>;
};