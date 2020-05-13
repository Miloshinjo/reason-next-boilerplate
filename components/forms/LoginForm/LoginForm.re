module Email = Util.Email;
module Password = Util.Password;
module Router = Next.Router;
open SharedStyles;
module LoginForm = [%form
  type input = {
    email: string,
    password: string,
  };
  type output = {
    email: Email.t,
    password: Password.t,
  };
  type submissionError =
    | InvalidCreds(string);
  let validators = {
    email: {
      strategy: OnFirstBlur,
      validate: ({email}) => email->Email.validate,
    },
    password: {
      strategy: OnFirstBlur,
      validate: ({password}) => password->Password.validate,
    },
  }
];

[@react.component]
let make = (~selected) => {
  let router = Router.useRouter();

  let form =
    LoginForm.useForm(
      ~initialInput={email: "milos@test.com", password: "password33"},
      ~onSubmit=(output, callbacks) => {
      Api.login(output.email, output.password)
      |> Js.Promise.then_(result => {
           switch (result) {
           | Ok(_) => router.push("/")
           | Error(err) =>
             callbacks.notifyOnFailure(InvalidCreds(err##message))
           };

           Js.Promise.resolve();
         })
      |> ignore
    });

  <form
    className={selected->authFormStyles}
    onSubmit={event => {
      event->ReactEvent.Form.preventDefault;
      form.submit();
    }}>
    <h2 className="text-2xl font-bold text-center mb-16">
      "Account Login"->React.string
    </h2>
    <TextInput
      id="login-email"
      placeholder="lolth@underdark.com"
      label="Email"
      value={form.input.email}
      disabled={form.submitting}
      onBlur={_ => form.blurEmail()}
      onChange={event => {
        form.dismissSubmissionResult();
        form.updateEmail(
          (input, value) => {...input, email: value},
          event->ReactEvent.Form.target##value,
        );
      }}
      error={form.emailResult}
    />
    <TextInput
      id="login-password"
      placeholder="Sp1derawes0me"
      type_="password"
      label="Password"
      value={form.input.password}
      disabled={form.submitting}
      onBlur={_ => form.blurPassword()}
      onChange={event => {
        form.dismissSubmissionResult();
        form.updatePassword(
          (input, value) => {...input, password: value},
          event->ReactEvent.Form.target##value,
        );
      }}
      error={form.passwordResult}
    />
    <div className="mt-8" />
    <FormButton disabled={form.submitting}>
      "Log in to your account!"->React.string
    </FormButton>
    {switch (form.status) {
     | SubmissionFailed(InvalidCreds(message)) =>
       <div className=formError> message->React.string </div>
     | _ => React.null
     }}
  </form>;
};