template <typename T1, typename T2>
struct isSameClass {
  static constexpr bool result = std::is_same<T1, T2>::value;
};

