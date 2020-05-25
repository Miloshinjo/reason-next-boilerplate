module Link = Next.Link;

[@react.component]
let make = () => {
  <header className="bg-primary text-white">
    <Link href="/">
      <h2
        className="text-xl uppercase font-black font-heading py-6 px-4 md:px-12 cursor-pointer">
        "DnD Armory"->React.string
      </h2>
    </Link>
  </header>;
};