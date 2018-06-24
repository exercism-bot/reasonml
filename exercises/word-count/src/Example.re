let wordCount = (input: string) =>
  input
  |> Js.String.toLowerCase
  |> Js.String.replaceByRe([%re "/[^'a-zA-Z0-9]+/g"], " ")
  |> Js.String.trim
  |> Js.String.splitByRe([%re "/'?\\s+'?/"])
  |> Js.Array.reduce(
       (dict, word) => {
         let count = Js.Dict.get(dict, word);

         switch (count) {
         | Some(value) => Js.Dict.set(dict, word, value + 1)
         | None => Js.Dict.set(dict, word, 1)
         };

         dict;
       },
       Js.Dict.empty(),
     )
  |> Js.Dict.entries;