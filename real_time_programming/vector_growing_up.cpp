

// if a std::vector's size get grown,
// it copies all the original into new address.

// C++ Weekly - Ep 235 - PMR: Amazing, Fast, But, Not Quite Magic
// take a look at : https://www.youtube.com/watch?v=vXJ1dwJ9QkI

// std::pmr::vector also contains potiner to buffer and length at first.

// print inner buffer in hex
// C++ Weekly - Ep 235 - PMR: Amazing, Fast, But, Not Quite Magic
// https://github.com/lefticus/cpp_weekly/blob/master/PMR/1_experiments.cpp
// template <typename ItrBegin, typename ItrEnd>
// void print_line(int offset, ItrBegin begin, const ItrEnd end) {
//   fmt::print("(dec) {:02x}:  {:3}\n", offset, fmt::join(begin, end, "  "));
//   fmt::print("(hex) {:02x}:   {:02x}\n", offset, fmt::join(begin, end, "   "));

//   fmt::print("(asc) {:02x}:", offset);
//   std::for_each(begin, end, [](const auto c) {
//     if (std::isgraph(c)) {
//       fmt::print("   {} ", static_cast<char>(c));
//     } else {
//       fmt::print(" \\{:03o}", c);
//     }
//   });

//   fmt::print("\n");
// }

// template <typename Buffer, typename Container>
// void print_buffer(const std::string_view title, const Buffer &buffer,
//                   const Container &container) {
//   fmt::print("==============={:^10}==============\n", title);

//   auto begin = buffer.begin();
//   fmt::print("Buffer Address Start: {}\n",
//              static_cast<const void *>(buffer.data()));
//   for (const auto &elem : container) {
//     fmt::print(" Item Address: {}\n", static_cast<const void *>(&elem));
//   }
//   for (std::size_t offset = 0; offset < buffer.size(); offset += 16) {
//     print_line(offset, std::next(begin, offset), std::next(begin, offset + 16));
//   }

//   fmt::print("\n");
// }

// short string optimization (sso)

std::pmr::monotonic_buffer
// also store address
