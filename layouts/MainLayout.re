module Head = Next.Head;

[@react.component]
let make = (~children) => {
  <>
    <Head>
      <meta
        name="viewport"
        content="width=device-width, initial-scale=1, shrink-to-fit=no, viewport-fit=cover"
      />
      <title> "DnD Armory"->React.string </title>
    </Head>
    <main> children </main>
  </>;
};

let default = make;