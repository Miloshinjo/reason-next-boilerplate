module Link = Next.Link;

[@react.component]
let make = () => {
  Hooks.useProtectRoute();
  <div>
    "Welcome to Reason Next Boilerplate"->React.string
    <Link href="/auth"> <a> "auth page"->React.string </a> </Link>
  </div>;
};

let default = make;