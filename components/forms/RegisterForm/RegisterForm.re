module Email = Util.Email;
module Auth = Util.Auth;
module Password = Util.Password;
module Router = Next.Router;

open SharedStyles;

module RegisterForm = [%form
  type input = {
    email: string,
    password: Password.t,
    passwordConfirm: Password.t,
  };
  type output = {
    email: Email.t,
    password: Password.t,
    passwordConfirm: Password.t,
  };
  type submissionError =
    | SubmissionError(string);
  let validators = {
    email: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: ({email}) => email->Email.validate,
    },
    password: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: ({password}) => {
        switch (password) {
        | "" => Error("Password is required")
        | _ when String.length(password) < 8 =>
          Error("Password must be at least 8 characters")
        | _ => Ok(password)
        };
      },
    },
    passwordConfirm: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: ({password, passwordConfirm}) => {
        switch (passwordConfirm) {
        | "" => Error("Passwords confirm is required")
        | _ when passwordConfirm !== password =>
          Error("Passwords do not match")
        | _ => Ok(passwordConfirm)
        };
      },
    },
  }
];

[@react.component]
let make = (~selected) => {
  let router = Router.useRouter();
  let form =
    RegisterForm.useForm(
      ~initialInput={email: "", password: "", passwordConfirm: ""},
      ~onSubmit=(output, callbacks) => {
      Api.register(output.email, output.password, output.passwordConfirm)
      |> Js.Promise.then_(result => {
           switch (result) {
           | Ok(_) => router->Auth.login
           | Error(err) => callbacks.notifyOnFailure(SubmissionError(err))
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
      "Create your account!"->React.string
    </h2>
    <TextInput
      id="register-email"
      placeholder="lolth@underdark.com"
      label="Email"
      value={form.input.email}
      disabled={form.submitting}
      onBlur={_ => form.blurEmail()}
      onChange={event =>
        form.updateEmail(
          (input, value) => {...input, email: value},
          event->ReactEvent.Form.target##value,
        )
      }
      error={form.emailResult}
    />
    <TextInput
      id="register-password"
      placeholder="Sp1derawes0me"
      type_="password"
      label="Password"
      value={form.input.password}
      disabled={form.submitting}
      onBlur={_ => form.blurPassword()}
      onChange={event =>
        form.updatePassword(
          (input, value) => {...input, password: value},
          event->ReactEvent.Form.target##value,
        )
      }
      error={form.passwordResult}
    />
    <TextInput
      id="register-password-confirm"
      placeholder="Sp1derawes0me"
      type_="password"
      label="Password Confirm"
      value={form.input.passwordConfirm}
      disabled={form.submitting}
      onBlur={_ => form.blurPasswordConfirm()}
      onChange={event =>
        form.updatePasswordConfirm(
          (input, value) => {...input, passwordConfirm: value},
          event->ReactEvent.Form.target##value,
        )
      }
      error={form.passwordConfirmResult}
    />
    <div className="mt-8" />
    <FormButton disabled={form.submitting}>
      "Register Now!"->React.string
    </FormButton>
  </form>;
};