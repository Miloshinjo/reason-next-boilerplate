module Link = Next.Link;

[@react.component]
let make = () => {
  Hooks.useProtectRoute();
  <div className="bg-image min-h-screen">
    "Welcome to Reason Next Boilerplate"->React.string
    <Link href="/spells">
      <a className="text-white"> "spells page"->React.string </a>
    </Link>
  </div>;
};

let default = make;