[@react.component]
let make = (~disabled, ~children) => {
  let buttonStyles = "bg-primary px-8 py-4 rounded-lg font-bold text-white focus:outline-none focus:shadow-outline";
  <button className=buttonStyles type_="submit" disabled> children </button>;
};