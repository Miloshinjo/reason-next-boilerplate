module Link = Next.Link;

[@react.component]
let make = () => {
  Hooks.useProtectRoute();
  <AppLayout>
    <div className="min-h-screen px-4 py-16 lg:w-2/3 mx-auto">
      <Link href="/spells">
        <a
          className="p-6 justify-center text-xl mb-2 lg:mb-0 w-full border-2 border-primary inline-flex text-primary font-bold uppercase hover:bg-gray-200 transition duration-200 mr-4">
          "spells library"->React.string
        </a>
      </Link>
      <Link href="/characters">
        <a
          className="p-6 justify-center text-xl border-2 w-full border-primary inline-flex text-primary font-bold uppercase hover:bg-gray-200 transition duration-200">
          "your characters"->React.string
        </a>
      </Link>
    </div>
  </AppLayout>;
};

let default = make;
