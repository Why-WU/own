<template>
  <header class="header" :style="{background:selectMenu.bgc}">
    <span class="header-home" @click="$router.push('/')">首页</span>
    <h4 class="header-title">{{selectMenu.title?selectMenu.title:'聊天'}}</h4>
  </header>
</template>

<script>
export default {
  props: ["selectMenu"]
};
</script>

<style scoped>
.header {
  height: 1rem;
  background-color: rgb(63, 81, 181);
  line-height: 1rem;
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  color: #000;
}
.header-title {
  position: absolute;
  top: 50%;
  left: 50%;
  transform: translate(-50%, -50%);
}
.header-home {
  margin-left: 0.2rem;
}
</style>
