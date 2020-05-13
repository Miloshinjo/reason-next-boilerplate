let authFormStyles = selected => {
  selected
    ? "flex flex-col p-8 xl:p-16 rounded-lg w-full sm:w-2/3 md:w-1/2 xl:w-full bg-white shadow xl:absolute xl:inset-x-0 xl:transition xl:duration-500 z-10 xl:ease"
    : "hidden xl:flex flex-col p-8 xl:p-16 rounded-lg bg-white shadow xl:absolute xl:inset-x-0 xl:transition xl:duration-500 xl:transform xl:translate-x-full z-1 opacity-0 xl:ease-out";
};

let formError = "mt-1 text-center text-yellow-600";