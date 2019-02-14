<template>
  <ul class="footer" :style="{background:footerbgc}">
    <li class="footer-menu" v-for="(menu,index) in menuList" :key="index">
      <router-link :to="menu.path">{{menu.title}}</router-link>
    </li>
  </ul>
</template>

<script>
export default {
  data() {
    return {};
  },
  props: ["menuList", "footerbgc"],
  methods: {
    
  },
};
</script>

<style scoped>
.footer {
  display: flex;
  position: fixed;
  bottom: 0;
  width: 100%;
  height: 1rem;
  line-height: 1rem;
  background-color:rgb(63, 81, 181);
}
.footer-menu {
  flex-grow: 1;
  text-align: center;
}
.footer li{
    list-style: none;
}
.footer-menu a{
    outline: none;
    color: #000;
}
.footer-menu a.router-link-active{
    color: #000
}
</style>
