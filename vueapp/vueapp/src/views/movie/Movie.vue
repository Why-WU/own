<template>
    <div>
        <h1>movie</h1>
    </div>
</template>

<script>
export default {
    created() {
        this.$emit("matchTab","movie")
    },
}
</script>

<style>
    div{
        margin-top: 50%;
    }
</style>