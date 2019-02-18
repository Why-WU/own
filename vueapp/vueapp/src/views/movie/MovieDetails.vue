<template>
  <div>
    <h1>123</h1>
    {{details.title}}
  </div>
</template>

<script>
import axios from "axios";
export default {
  data() {
    return {
      details: {}
    };
  },
  created() {
    this.getDetails();
    console.log(this.$route.params.id);
  },
  methods: {
    getDetails() {
      let proxy = "https://bird.ioliu.cn/v2?url=";
      let url = `https://api.douban.com/v2/movie/subject/${
        this.$route.params.id
      }`;
      axios.get(proxy + url).then(res => {
        this.details = res.data;
      });
    }
  }
};
</script>


