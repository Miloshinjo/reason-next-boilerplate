module Link = Next.Link;

[@react.component]
let make = () => {
  Hooks.useProtectRoute();
  <AppLayout>
    <div className="min-h-screen">
      "Welcome to Reason Next Boilerplate"->React.string
      <Link href="/spells"> <a> "spells page"->React.string </a> </Link>
    </div>
  </AppLayout>;
};

let default = make;