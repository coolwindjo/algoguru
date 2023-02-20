git add _posts/ assets/img/posting
docker compose up
git clean -fdx
rm -rf $(find . -name "*.out")
