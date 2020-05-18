module Router = Next.Router;

let useProtectRoute = () => {
  let router = Router.useRouter();

  React.useEffect0(() => {
    let isAuthenticated =
      Dom.Storage.(localStorage |> getItem("isAuthenticated"));

    switch (isAuthenticated) {
    | Some(_) => ()
    | None => router.push("/auth")
    };

    None;
  });
};

let useRedirectFromAuth = () => {
  let router = Router.useRouter();

  React.useEffect0(() => {
    let isAuthenticated =
      Dom.Storage.(localStorage |> getItem("isAuthenticated"));

    switch (isAuthenticated) {
    | Some(_) => router.push("/")
    | None => ()
    };

    None;
  });
};