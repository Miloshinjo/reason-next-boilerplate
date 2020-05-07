module Email = Util.Email;

let formStyles = selected => {
  selected
    ? "flex flex-col p-16 rounded-lg bg-white shadow absolute inset-x-0 transition duration-500 z-10 ease"
    : "flex flex-col p-16 rounded-lg bg-white shadow absolute inset-x-0 transition duration-500 transform translate-x-full z-1 opacity-0 ease-out";
};

module RegisterForm = [%form
  type input = {
    email: string,
    password: string,
    passwordConfirm: string,
  };
  type output = {
    email: Email.t,
    password: string,
    passwordConfirm: string,
  };
  let validators = {
    email: {
      strategy: OnFirstBlur,
      validate: ({email}) => email->Email.validate,
    },
    password: {
      strategy: OnFirstBlur,
      validate: input => {
        switch (input.password) {
        | "" => Error("Password is required")
        | _ => Ok(input.password)
        };
      },
    },
    passwordConfirm: {
      strategy: OnFirstBlur,
      validate: input => {
        switch (input.passwordConfirm) {
        | "" => Error("Passwords must match is required")
        | _ => Ok(input.passwordConfirm)
        };
      },
    },
  }
];

[@react.component]
let make = (~selected) => {
  let form =
    RegisterForm.useForm(
      ~initialInput={email: "", password: "", passwordConfirm: ""},
      ~onSubmit=(output, cb) => {
      cb.reset()
    });

  <form
    className={selected->formStyles}
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