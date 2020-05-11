let unwrap = x =>
  fun
  | Some(x) => x
  | None => None;
