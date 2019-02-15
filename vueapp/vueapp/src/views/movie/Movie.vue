<template>
  <div>
    <h1>movie</h1>
  </div>
</template>

<script>
export default {
  created() {
    this.$emit("matchTab", "movie");
    this.getData();
  },
  methods: {
    getData() {
      let proxy = "https://bird.ioliu.cn/v1?url=";
      let url =
        "https://api.douban.com/v2/movie/in_theaters?city=广州&start=0&count=10";
      axios
        .get(proxy + url)
        .then(function(res) {
            console.log(res)
        })
        .catch(function(res) {
          console.log(0);
        });
    }
  }
};
</script>

<style>
div {
  margin-top: 50%;
}
</style>