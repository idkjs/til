/* 他のファイルから参照する場合は、ファイル名(capitalize).Sample になる */
module Sample = {
  let hello = print_endline("Hello, World!");
};

/* 別名で使用する */
module MyCore = Core;

let () = {
  MyCore.print_endline("hello");
  Sample.hello;
};
