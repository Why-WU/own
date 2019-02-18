<template>
  <div>
    <aplayer autoplay :music="musicList[0]" :list="musicList" v-if="isShow" :showLrc="true"/>
  </div>
</template>

<script>
import Aplayer from "vue-aplayer";
import axios from "axios";
export default {
  components: { Aplayer },
  data() {
    return {
      musicList: [],
      isShow: false
    };
  },
  created() {
    this.getData();
  },
  methods: {
    getData() {
      axios.get("./data/musicdata.json").then(res => {
        let arr = res.data.musicData;
        arr.forEach((element, index) => {
          arr[index].lrc = location.origin + location.pathname + element.lrc;
        });
        this.musicList = arr;
        this.isShow = true;
      });
    }
  }
};
</script>

<style scoped>
div {
  margin-top: 1rem;
}
</style>
